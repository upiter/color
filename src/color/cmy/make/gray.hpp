#ifndef color_cmy_make_gray50
#define color_cmy_make_gray50

// ::color::make::gray50( c )

 namespace color
  {
   namespace make
    { //RGB equivalents: std::array<double,3>( { 0.5, 0.5, 0.5 } ) - rgb(127,127,127) - #7F7F7F

     template< typename tag_name >
      inline
      void gray
       (
                  ::color::model< ::color::category::cmy< tag_name > > & color_parameter
        ,typename ::color::trait::scalar< ::color::category::cmy< tag_name > >::input_const_type    percent
       )
       {
        typedef ::color::category::cmy< tag_name >      category_left_type;
        typedef ::color::model< category_left_type  >            left_type;

        typedef ::color::cmy< double >      right_type;

        color_parameter = right_type( { 1-percent/100, 1-percent/100, 1-percent/100 } );
       }

     template< typename tag_name >
      inline
      void gray50( ::color::model< ::color::category::cmy< tag_name > > & color_parameter )
       {
        typedef ::color::category::cmy< tag_name >         category_left_type;
        typedef ::color::model< category_left_type  > left_type;

        typedef ::color::cmy< double >      right_type;

        static left_type local( right_type( { 0.5, 0.5, 0.5 } ) );

        color_parameter = local;
       }

    }
  }

#endif
