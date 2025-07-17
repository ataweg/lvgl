Merge lvgl                                                2023-05-15, A.Werner
------------------------------------------------------------------------------

https://github.com/lvgl/lvgl
using master


mklink /j demos    F:\Projects\InternetOfThings\_Tools\LVGL_Simulator.dev\LvglPlatform\lvgl\demos
mklink /j examples F:\Projects\InternetOfThings\_Tools\LVGL_Simulator.dev\LvglPlatform\lvgl\examples


modified files
--------------
only the example folder has modifications
the src folder has NO modifications

	.\examples\widgets\keyboard\font_montserrat_ger_14.c
	.\examples\widgets\keyboard\font_montserrat_ger_16.c
	.\examples\widgets\keyboard\lv_example_keyboard_4.c

	.\examples\widgets\lv_example_widgets.h(1): # modified by AWe
	.\examples\widgets\chart\lv_example_chart_1.c(1): // modified by AWe
	.\examples\widgets\keyboard\index.rst(1): # modified by AWe

2024-03-21
----------
update to version 9.1.1
commit 691554ded85613af6ad06bba655f8e665fd661a4 (HEAD, origin/master, origin/HEAD, master)
Author: pengyiqiang <pengyiqiang@xiaomi.com>
Date:   Fri Apr 19 20:20:10 2024 +0800

2024-03-21
----------
update to release 9.1
commit c5109ccceb5e4da741512471401916bafedc34fd (HEAD -> release/v9.1, origin/release/v9.1)
Author: Gabor Kiss-Vamosi <kisvegabor@gmail.com>
Date:   Wed Mar 20 09:01:01 2024 +0100

2024-02-14
----------
update to release 9.0
commit 51b8d8e4ea7ed4cb7a4ad295234740b81fc46e6b (HEAD -> release/v9.0, origin/release/v9.0)
Author: Gabriel Wang <gabriel.wang@arm.com>
Date:   Mon Jan 22 17:05:05 2024 +0000

2024-02-06
----------
updated to commit 099f0cd805807eed08dd573603e26d60becf6e70 (HEAD -> release/v8.3, origin/release/v8.3)
Author: Gabor Kiss-Vamosi <kisvegabor@gmail.com>
Date:   Mon Jan 29 12:21:37 2024 +0100
    demo(music): add png assets

updated files:
   extra\widgets\calendar\lv_calendar_header_dropdown.c
   extra\widgets\calendar\lv_calendar_header_dropdown.h

2024-01-06
----------
update LVGL to version 8.3.11
commit f2c103260f3ac5a1a8c50af348b994ef8153796d (HEAD -> release/v8.3, origin/release/v8.3)
Author: Gabriel Wang <gabriel.wang@arm.com>
Date:   Wed Jan 3 09:24:27 2024 +0000

changes
-------
env_support\cmake\esp.cmake

2023-11-18
----------
update LVGL to version 8.3.10
commit c16bfdc2271174c924ed5c76b38141f6c208a684 (HEAD -> release/v8.3, origin/release/v8.3)
Author: Neo Xu <neo.xu1990@gmail.com>
Date:   Tue Nov 14 21:21:47 2023 +0800
    fix(obj): fix arduino compile warnings (#4807)
    Signed-off-by: Neo Xu <neo.xu1990@gmail.com>

2023-10-08
----------
update LVGL to version 8.3.9
commit d22cda3cdb15cee95763491db95753980846d9f9 (HEAD -> release/v8.3, origin/release/v8.3)
Author: Gabor Kiss-Vamosi <kisvegabor@gmail.com>
Date:   Fri Oct 6 09:57:12 2023 +0200
    fix: fix warning in lv_draw_sw_letter.c

modified files
--------------
.\lvgl\env_support\cmake\esp.cmake
   remove ${LVGL_ROOT_DIR}/examples ${LVGL_ROOT_DIR}/demos from build
   add arduino to REQUIRES

You are using the development version of LVGL which is not stable at this moment.
For production use the release/v8.3 branch. To silence this warning add
#define LV_USE_DEV_VERSION to lv_conf.h" [-Wcpp]

------------------------------------------------------------------------------
Get and update lvgl
-------------------
lvgl has no submodules yet

pushd F:\working\GIT
git clone https://github.com/lvgl/lvgl.git

Update lvgl
-----------
pushd F:\working\GIT\lvgl
cd lvgl
git pull
git checkout release/v8.3
popd

pushd F:\working\GIT_beautified\lvgl
rmdir /s /q lvgl.old
move lvgl lvgl.old
mkdir lvgl
xcopy /Y /S F:\working\GIT\lvgl\lvgl lvgl

cd lvgl
"C:\Program Files (x86)\Astyle\astyle.exe" -A1 -s3 -c -D -S -p -U -z1 -xW -xl -xb -y -N -m2 -O -o -C -R *.c* *.h *.ino
del /s .\*.orig .\*.bak

set MERGE="C:\Program Files (x86)\Araxis\Araxis Merge 2001 v6.0 Professional\Merge.exe"
%MERGE% F:\working\GIT_beautified\lvgl\lvgl.old  F:\working\GIT_beautified\lvgl\lvgl
%MERGE% F:\working\GIT_beautified\lvgl\lvgl      F:\Projects\InternetOfThings\Devices\Wifi-WeatherStation\Firmware\Wifi-WeatherStation\source\components\lvgl

popd
