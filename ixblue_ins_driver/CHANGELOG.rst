^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Changelog for package ixblue_ins_driver
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

0.2.0 (2023-10-24)
------------------
* Migrated to ROS 2 Humble.

0.1.5 (2020-11-13)
------------------
* Use new std_bin_decoder API to reconstruct incomplete frames
  Avoid the copy of the frame in this driver
* Contributors: Romain Reignier

0.1.4 (2020-10-27)
------------------
* Add a param to use compensated acceleration (changes previous behavior)
* Add diagnostics publication
* Change default frame_id in launch to match node default
* Fix orientation quaternion content and make NED convention explicit.
* Bump minimum CMake version to avoid CMP0048 on Noetic buildfarm
* Contributors: BARRAL Adrien, Romain Reignier

0.1.3 (2020-09-01)
------------------
* Add boost thread as test dependency to fix Debian Stretch build
* Contributors: Romain Reignier

0.1.2 (2020-08-31)
------------------
* Fix packets_replayer build by adding CMake package Threads
* Contributors: Romain Reignier

0.1.1 (2020-08-28)
------------------
* Fix boost dependency for Noetic release
  Only build the packets_replayer if tests are being built
* Breaking change: Rename ins.msg to Ins.msg and iX/ins topic to ix/ins topic to follow ROS coding style
  - In ROS, message names are CamelCase
  - Topics are in lower case
* Publish ROS time in header of TimeReference message
* Contributors: BARRAL Adrien, Romain Reignier

0.1.0 (2020-08-27)
------------------
* Prepare ROS release
* Add unit test on ROSPublisher::toNavSatFix()
* Prepare files catkin for release
* Switch stdbin data received log to debug level
* Default packets_replayer port is now the same than driver
  And add missing newline at the end of error message
* ixblue_stdbin_decoder can now be a package within the ROS workspace and
  not only a system library anymore
* Apply ixblue_stdbin_decoder changes on namespace and include dir name
* Build packets_replayer only if PCAP dev package is found
* Initial Commit.
* Contributors: Adrien BARRAL, Romain Reignier
