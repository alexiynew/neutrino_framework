#ifndef MATH_INC_CONSTANTS_HPP
#define MATH_INC_CONSTANTS_HPP

namespace neutrino::math
{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @addtogroup math_predefined_constants
/// @{
///
/// @name Predefined constants
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
inline constexpr T deg_to_rad = T(0.017453292519943295769236907684886127134428718885417254560);
template <class T>
inline constexpr T rad_to_deg = T(57.29577951308232087679815481410517033240547246656432154916);

template <class T>
inline constexpr T pi = T(3.141592653589793238462643383279502884197169399375105820974);
template <class T>
inline constexpr T tau = T(6.283185307179586476925286766559005768394338798750211641949);
template <class T>
inline constexpr T half_pi = T(1.570796326794896619231321691639751442098584699687552910487);
template <class T>
inline constexpr T three_over_two_pi = T(4.712388980384689857693965074919254326295754099062658731462);
template <class T>
inline constexpr T quarter_pi = T(0.785398163397448309615660845819875721049292349843776455243);
template <class T>
inline constexpr T one_over_pi = T(0.318309886183790671537767526745028724068919291480912897495);
template <class T>
inline constexpr T one_over_two_pi = T(0.159154943091895335768883763372514362034459645740456448747);
template <class T>
inline constexpr T two_over_pi = T(0.636619772367581343075535053490057448137838582961825794990);
template <class T>
inline constexpr T four_over_pi = T(1.273239544735162686151070106980114896275677165923651589981);
template <class T>
inline constexpr T two_over_root_pi = T(1.128379167095512573896158903121545171688101258657997713688);
template <class T>
inline constexpr T one_over_root_two = T(0.707106781186547524400844362104849039284835937688474036588);
template <class T>
inline constexpr T root_half_pi = T(1.253314137315500251207882642405522626503493370304969158314);
template <class T>
inline constexpr T root_two_pi = T(2.506628274631000502415765284811045253006986740609938316629);
template <class T>
inline constexpr T root_pi = T(1.772453850905516027298167483341145182797549456122387128213);

template <class T>
inline constexpr T root_two = T(1.414213562373095048801688724209698078569671875376948073176);
template <class T>
inline constexpr T root_three = T(1.732050807568877293527446341505872366942805253810380628055);
template <class T>
inline constexpr T root_five = T(2.236067977499789696409173668731276235440618359611525724270);

template <class T>
inline constexpr T ln_two = T(0.693147180559945309417232121458176568075500134360255254120);
template <class T>
inline constexpr T ln_ten = T(2.302585092994045684017991454684364207601101488628772976033);
template <class T>
inline constexpr T ln_ln_two = T(-0.36651292058166432701243915823266946945426344783710526305);
template <class T>
inline constexpr T root_ln_four = T(1.177410022515474691011569326459699637747385689385820538522);

template <class T>
inline constexpr T third = T(0.333333333333333333333333333333333333333333333333333333333);
template <class T>
inline constexpr T two_thirds = T(0.666666666666666666666666666666666666666666666666666666666);
template <class T>
inline constexpr T golden_ratio = T(1.618033988749894848204586834365638117720309179805762862135);

template <class T>
inline constexpr T e = T(2.718281828459045235360287471352662497757247093699959574966);
template <class T>
inline constexpr T euler = T(0.577215664901532860606512090082402431042159335939923598805);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
///
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

} // namespace neutrino::math

#endif
