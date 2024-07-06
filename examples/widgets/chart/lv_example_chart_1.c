// modified by AWe

#include "../../lv_examples.h"
#if LV_USE_CHART && LV_BUILD_EXAMPLES

#if 0
/**
 * A very basic line chart
 */
void lv_example_chart_1(void)
{
    /*Create a chart*/
    lv_obj_t * chart;
    chart = lv_chart_create(lv_screen_active());
    lv_obj_set_size(chart, 200, 150);
    lv_obj_center(chart);
    lv_chart_set_type(chart, LV_CHART_TYPE_LINE);   /*Show lines and points too*/

    /*Add two data series*/
    lv_chart_series_t * ser1 = lv_chart_add_series(chart, lv_palette_main(LV_PALETTE_GREEN), LV_CHART_AXIS_PRIMARY_Y);
    lv_chart_series_t * ser2 = lv_chart_add_series(chart, lv_palette_main(LV_PALETTE_RED), LV_CHART_AXIS_SECONDARY_Y);

    uint32_t i;
    for(i = 0; i < 10; i++) {
        /*Set the next points on 'ser1'*/
        lv_chart_set_next_value(chart, ser1, lv_rand(10, 50));

        /*Directly set points on 'ser2'*/
        ser2->y_points[i] = lv_rand(50, 90);
    }

    lv_chart_refresh(chart); /*Required after direct set*/
}
#elif 0
/**
 * A very basic line chart with horizontal and vertical axis
 */
void lv_example_chart_1(void)
{
    static lv_style_t style_chart;

    // style_chart: transparent, no border, no pad
    lv_style_init( &style_chart );
    lv_style_set_border_width( &style_chart, 1 );
    lv_style_set_radius( &style_chart, 0 );
//    lv_style_set_outline_pad( &style_chart, 0 );
//    lv_style_set_pad_all( &style_chart, 0 );

    lv_obj_set_size(lv_screen_active(), 480, 320 );

    /*Create a container*/
    lv_obj_t * main_cont = lv_obj_create(lv_screen_active());
    lv_obj_set_style_pad_all( main_cont, 0, 0 );
    lv_obj_set_size(main_cont, 480, 320 );
    lv_obj_center(main_cont);

    /*Create a chart*/
    lv_obj_t * chart = lv_chart_create(main_cont);
    lv_obj_add_style( chart, &style_chart, 0 );
    lv_obj_set_size(chart, 400, 240);
    lv_obj_set_style_pad_all( chart, 0, 0 );
    lv_obj_set_pos( chart, 40, 40 );

    lv_chart_set_type(chart, LV_CHART_TYPE_LINE);   /*Show lines and points too*/
    lv_chart_set_range(chart, LV_CHART_AXIS_PRIMARY_Y, 10, 50);
    lv_chart_set_range(chart, LV_CHART_AXIS_SECONDARY_Y, 50, 90);
    lv_chart_set_point_count(chart, 10);
    // Do not display points on the data
    lv_obj_set_style_size( chart, 0, 0, LV_PART_INDICATOR );

    /*Create a scale also with 100% width*/
    lv_obj_t * scale_bottom = lv_scale_create(main_cont);
    lv_obj_set_pos( scale_bottom, 40, 280 );
    lv_scale_set_mode(scale_bottom, LV_SCALE_MODE_HORIZONTAL_BOTTOM);
    lv_obj_set_size(scale_bottom, 400, 25);
    lv_scale_set_total_tick_count(scale_bottom, 11);
    lv_scale_set_major_tick_every(scale_bottom, 5);
    lv_obj_set_style_length(scale_bottom, 5, LV_PART_ITEMS);
    lv_obj_set_style_length(scale_bottom, 10, LV_PART_INDICATOR);
    lv_scale_set_range(scale_bottom, 10, 40);

    // create a left vertical scale
    lv_obj_t * scale_left = lv_scale_create(main_cont);
    lv_obj_set_pos( scale_left, 40 - 25, 40 );
    lv_scale_set_mode(scale_left, LV_SCALE_MODE_VERTICAL_LEFT);
    lv_obj_set_size(scale_left, 25, 240);
    lv_scale_set_total_tick_count(scale_left, 11);
    lv_scale_set_major_tick_every(scale_left, 5);
    lv_obj_set_style_length(scale_left, 5, LV_PART_ITEMS);
    lv_obj_set_style_length(scale_left, 10, LV_PART_INDICATOR);
    lv_scale_set_range(scale_left, 10, 50);

    // create a right vertical scale
    lv_obj_t * scale_right = lv_scale_create(main_cont);
    lv_obj_set_pos( scale_right, 440, 40 );
    lv_scale_set_mode(scale_right, LV_SCALE_MODE_VERTICAL_RIGHT);
    lv_obj_set_size(scale_right, 25, 240);
    lv_scale_set_total_tick_count(scale_right, 11);
    lv_scale_set_major_tick_every(scale_right, 5);
    lv_obj_set_style_length(scale_right, 5, LV_PART_ITEMS);
    lv_obj_set_style_length(scale_right, 10, LV_PART_INDICATOR);
    lv_scale_set_range(scale_right, 10, 90);

    /*Add two data series*/
    lv_chart_series_t * ser1 = lv_chart_add_series(chart, lv_palette_main(LV_PALETTE_GREEN), LV_CHART_AXIS_PRIMARY_Y);
    lv_chart_series_t * ser2 = lv_chart_add_series(chart, lv_palette_main(LV_PALETTE_RED), LV_CHART_AXIS_SECONDARY_Y);

    uint32_t i;
    for(i = 0; i < 10; i++) {lv_obj_get_y2( chart ),
        /*Set the next points on 'ser1'*/
        lv_chart_set_next_value(chart, ser1, lv_rand(10, 50));

        /*Directly set points on 'ser2'*/
        ser2->y_points[i] = lv_rand(50, 90);
    }

    lv_chart_refresh(chart); /*Required after direct set*/
}
#else
// we have a chart and want to a scale
// parameter defeined by the user are
//   where
//   range
//   size of ticks  (style)

void setScaleStyle( lv_obj_t * scale, int num_major_ticks, int num_minor_ticks )
{
   lv_scale_set_total_tick_count( scale, num_major_ticks );
   lv_scale_set_major_tick_every( scale, num_minor_ticks );
   lv_obj_set_style_length( scale, 5, LV_PART_ITEMS );
   lv_obj_set_style_length( scale, 10, LV_PART_INDICATOR );
}

void addScale( lv_obj_t * chart, lv_chart_axis_t axis, int32_t scale_size, int32_t range_min, int32_t range_max )
{
   // add a scale to a chart
   lv_obj_t * scale = ( lv_obj_t *  )lv_scale_create( chart );

   lv_scale_mode_t scale_mode;

   // get size and position of chart (parent)
   int32_t chart_pos_x  = lv_obj_get_x( chart );
   int32_t chart_pos_y  = lv_obj_get_y( chart );
   int32_t chart_width  = lv_obj_get_width( chart );
   int32_t chart_height = lv_obj_get_height( chart );

   switch( axis )
   {
      case LV_CHART_AXIS_PRIMARY_Y:
         scale_mode = LV_SCALE_MODE_VERTICAL_RIGHT;
         lv_obj_set_size( scale, scale_size, chart_height );
         lv_obj_set_pos( scale, chart_pos_x + chart_width, chart_pos_y );
         break;
      case LV_CHART_AXIS_SECONDARY_Y:
         scale_mode = LV_SCALE_MODE_VERTICAL_LEFT;
         lv_obj_set_size( scale, scale_size, chart_height );
         lv_obj_set_pos( scale, chart_pos_x, chart_pos_y );
         break;
      case LV_CHART_AXIS_PRIMARY_X:
         scale_mode = LV_SCALE_MODE_HORIZONTAL_BOTTOM;
         lv_obj_set_size( scale, chart_width, scale_size );
         break;
      case LV_CHART_AXIS_SECONDARY_X:
         scale_mode = LV_SCALE_MODE_HORIZONTAL_TOP;
         lv_obj_set_size( scale, chart_width, scale_size );
         break;
      default:
         LV_LOG_WARN( "Invalid axis: %d", axis );
         return;
   }

    lv_scale_set_range( scale, range_min, range_max );
}


/**
 * A very basic line chart with horizontal and vertical axis
 */
void lv_example_chart_1(void)
{
    static lv_style_t style_chart;

    // style_chart: transparent, no border, no pad
    lv_style_init(&style_chart);
    lv_style_set_border_width(&style_chart, 1);
    lv_style_set_radius(&style_chart, 0);
    //    lv_style_set_outline_pad( &style_chart, 0 );
    //    lv_style_set_pad_all( &style_chart, 0 );

    lv_obj_set_size(lv_screen_active(), 480, 320);

    /*Create a container*/
    lv_obj_t* main_cont = lv_obj_create(lv_screen_active());
    lv_obj_set_style_pad_all(main_cont, 0, 0);
    lv_obj_set_size(main_cont, 480, 320);
    lv_obj_center(main_cont);

    /*Create a chart*/
    lv_obj_t* chart = lv_chart_create(main_cont);
    lv_obj_add_style(chart, &style_chart, 0);
    lv_obj_set_size(chart, 400, 240);
    lv_obj_set_style_pad_all(chart, 0, 0);
    lv_obj_set_pos(chart, 40, 40);

    lv_chart_set_type(chart, LV_CHART_TYPE_LINE);   /*Show lines and points too*/
    lv_chart_set_range(chart, LV_CHART_AXIS_PRIMARY_Y, 10, 50);
    lv_chart_set_range(chart, LV_CHART_AXIS_SECONDARY_Y, 50, 90);
    lv_chart_set_point_count(chart, 10);
    // Do not display points on the data
    lv_obj_set_style_size(chart, 0, 0, LV_PART_INDICATOR);

    addScale(chart, LV_CHART_AXIS_PRIMARY_X, 25, 10, 40 );
    addScale(chart, LV_CHART_AXIS_PRIMARY_Y, 25, 10, 50 );
    addScale(chart, LV_CHART_AXIS_SECONDARY_Y, 25, 10, 50 );

    /*Add two data series*/
    lv_chart_series_t * ser1 = lv_chart_add_series(chart, lv_palette_main(LV_PALETTE_GREEN), LV_CHART_AXIS_PRIMARY_Y);
    lv_chart_series_t * ser2 = lv_chart_add_series(chart, lv_palette_main(LV_PALETTE_RED), LV_CHART_AXIS_SECONDARY_Y);

    uint32_t i;
    for(i = 0; i < 10; i++) {lv_obj_get_y2( chart ),
        /*Set the next points on 'ser1'*/
        lv_chart_set_next_value(chart, ser1, lv_rand(10, 50));

        /*Directly set points on 'ser2'*/
        ser2->y_points[i] = lv_rand(50, 90);
    }

    lv_chart_refresh(chart); /*Required after direct set*/
}
#endif

#endif
