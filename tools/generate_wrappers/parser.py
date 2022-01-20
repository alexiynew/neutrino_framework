from xml.etree import ElementTree
import requests
import urllib.parse
import os


class Type:
    def __init__(self, xml_type):
        if xml_type.get('name'):
            self.type_string = ""
            self.name = ""
        else:
            self.type_string = " ".join(xml_type.itertext())
            self.name = xml_type.find('name').text

        self.requires = xml_type.get('requires')


class Enum:
    def __init__(self, enum):
        self.name = enum.get('name')
        self.value = enum.get('value')

        t = enum.get('type')
        self.type = t if t else ""

        g = enum.get('group')
        self.groups = g.split(',') if g else []


class Proto:
    def __init__(self, proto):
        self.name = proto.find('name').text
        self.type = " ".join(proto.itertext())[:-len(self.name)]

        ptype = proto.find('ptype')
        if ptype != None:
            self.requires = ptype.text
        else:
            self.requires = ""


class Param:
    def __init__(self, param):
        self.string = " ".join(param.itertext())
        self.name = param.find('name').text

        ptype = param.find('ptype')
        if ptype != None:
            self.requires = ptype.text
        else:
            self.requires = ""


class Command:
    def __init__(self, command):
        self.prototype = Proto(command.find('proto'))

        self.params = []
        for param in command.findall('param'):
            self.params.append(Param(param))


class Require:
    def __init__(self, require):
        c = require.get('comment')
        self.comment = c if c != None else ""

        p = require.get('profile')
        self.profile = p if p != None else ""

        self.type_names = []
        for t in require.findall('type'):
            self.type_names.append(t.get('name'))

        self.enum_names = []
        for enum in require.findall('enum'):
            self.enum_names.append(enum.get('name'))

        self.command_names = []
        for command in require.findall('command'):
            self.command_names.append(command.get('name'))


class Remove:
    def __init__(self, r):
        p = r.get('profile')
        self.profile = p if p != None else ""

        self.enum_names = []
        for enum in r.findall('enum'):
            self.enum_names.append(enum.get('name'))

        self.command_names = []
        for command in r.findall('command'):
            self.command_names.append(command.get('name'))


class Feature:
    def __init__(self, feature):
        self.name = feature.get('name')
        self.api = feature.get('api')
        self.number = feature.get('number')

        self.require = []
        for r in feature.findall('require'):
            self.require.append(Require(r))

        self.remove = []
        for r in feature.findall('remove'):
            self.remove.append(Remove(r))


class Extension:
    def __init__(self, extension):
        self.name = extension.get('name')
        self.supported = extension.get('supported').split('|')

        self.require = []
        for r in extension.findall('require'):
            self.require.append(Require(r))


class Registry:
    def __init__(self, xml_file):
        xml_tree = ElementTree.parse(xml_file)

        self.enums = {}
        for node in xml_tree.findall('enums/enum'):
            e = Enum(node)
            self.enums[e.name] = e

        self.commands = {}
        for node in xml_tree.findall('commands/command'):
            c = Command(node)
            self.commands[c.prototype.name] = c

        self.types = {}
        for node in xml_tree.findall('types/type'):
            t = Type(node)
            self.types[t.name] = t

        self.extensions = []
        for ext in xml_tree.findall('extensions/extension'):
            e = Extension(ext)
            self.extensions.append(e)

        self.features = []
        for feature in xml_tree.findall('feature'):
            f = Feature(feature)
            self.features.append(f)


def parse(file):
    url_base = "https://raw.githubusercontent.com/KhronosGroup/OpenGL-Registry/main/xml/"

    xml_url = url_base + file

    print(f"Geting: {xml_url}")
    with requests.get(xml_url) as response, open(file, 'wb') as out_file:
        out_file.write(response.content)

    r = Registry(file)

    os.remove(file)

    return r
