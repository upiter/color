#ifndef color_type_split4
#define color_type_split4

// ::color::type::split4_t

namespace color
 {
  namespace type
   {

    template< unsigned first_size, unsigned second_size, unsigned third_size, unsigned fourth_size >
     struct split4_t {};

    typedef  ::color::type::split4_t<  2,  2,  2,  2 > split2222_t, split2222_type;

    typedef  ::color::type::split4_t<  4,  4,  4,  4 > split4444_t, split4444_type;

    typedef  ::color::type::split4_t<  5,  5,  5,  1 > split5551_t, split5551_type;
    typedef  ::color::type::split4_t<  1,  5,  5,  5 > split1555_t, split1555_type;

    typedef  ::color::type::split4_t<  6,  6,  6,  6 > split6666_t, split6666_type;

    typedef  ::color::type::split4_t<  8,  8,  8,  8 > split8888_t, split8888_type;

    typedef  ::color::type::split4_t<  2, 10, 10, 10 > split2AAA_t, split2AAA_type;
    typedef  ::color::type::split4_t< 10, 10, 10,  2 > splitAAA2_t, splitAAA2_type;

    typedef  ::color::type::split4_t< 16, 16, 16, 16 > splitGGGG_t, splitGGGG_type;

   }
 }

#endif
