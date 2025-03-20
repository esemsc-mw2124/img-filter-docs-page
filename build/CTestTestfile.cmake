# CMake generated Testfile for 
# Source directory: /Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection
# Build directory: /Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test([=[Brightness1]=] "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/build/APImageFilters" "-i" "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/Images/small.png" "-b" "100" "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/build/output/brightness1.png")
set_tests_properties([=[Brightness1]=] PROPERTIES  TIMEOUT "10" _BACKTRACE_TRIPLES "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/cmdtests.cmake;10;add_test;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/cmdtests.cmake;0;;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/CMakeLists.txt;56;include;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/CMakeLists.txt;0;")
add_test([=[Brightness2]=] "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/build/APImageFilters" "-i" "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/Images/small.png" "--brightness" "-100" "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/build/output/brightness2.png")
set_tests_properties([=[Brightness2]=] PROPERTIES  TIMEOUT "10" _BACKTRACE_TRIPLES "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/cmdtests.cmake;11;add_test;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/cmdtests.cmake;0;;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/CMakeLists.txt;56;include;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/CMakeLists.txt;0;")
add_test([=[Greyscale1]=] "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/build/APImageFilters" "-i" "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/Images/small.png" "-g" "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/build/output/greyscale1.png")
set_tests_properties([=[Greyscale1]=] PROPERTIES  TIMEOUT "10" _BACKTRACE_TRIPLES "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/cmdtests.cmake;12;add_test;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/cmdtests.cmake;0;;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/CMakeLists.txt;56;include;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/CMakeLists.txt;0;")
add_test([=[Greyscale2]=] "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/build/APImageFilters" "-i" "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/Images/small.png" "--greyscale" "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/build/output/greyscale2.png")
set_tests_properties([=[Greyscale2]=] PROPERTIES  TIMEOUT "10" _BACKTRACE_TRIPLES "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/cmdtests.cmake;13;add_test;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/cmdtests.cmake;0;;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/CMakeLists.txt;56;include;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/CMakeLists.txt;0;")
add_test([=[HistogramHSV]=] "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/build/APImageFilters" "-i" "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/Images/small.png" "-h" "HSV" "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/build/output/histogram1.png")
set_tests_properties([=[HistogramHSV]=] PROPERTIES  TIMEOUT "10" _BACKTRACE_TRIPLES "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/cmdtests.cmake;14;add_test;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/cmdtests.cmake;0;;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/CMakeLists.txt;56;include;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/CMakeLists.txt;0;")
add_test([=[HistogramHSL]=] "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/build/APImageFilters" "-i" "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/Images/small.png" "--histogram" "HSL" "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/build/output/histogram2.png")
set_tests_properties([=[HistogramHSL]=] PROPERTIES  TIMEOUT "10" _BACKTRACE_TRIPLES "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/cmdtests.cmake;15;add_test;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/cmdtests.cmake;0;;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/CMakeLists.txt;56;include;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/CMakeLists.txt;0;")
add_test([=[BlurGaussian]=] "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/build/APImageFilters" "-i" "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/Images/small.png" "-r" "Gaussian" "5" "2.0" "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/build/output/blur1.png")
set_tests_properties([=[BlurGaussian]=] PROPERTIES  TIMEOUT "10" _BACKTRACE_TRIPLES "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/cmdtests.cmake;16;add_test;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/cmdtests.cmake;0;;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/CMakeLists.txt;56;include;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/CMakeLists.txt;0;")
add_test([=[BlurBox]=] "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/build/APImageFilters" "-i" "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/Images/small.png" "-r" "Box" "7" "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/build/output/blur2.png")
set_tests_properties([=[BlurBox]=] PROPERTIES  TIMEOUT "10" _BACKTRACE_TRIPLES "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/cmdtests.cmake;17;add_test;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/cmdtests.cmake;0;;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/CMakeLists.txt;56;include;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/CMakeLists.txt;0;")
add_test([=[BlurMedian]=] "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/build/APImageFilters" "-i" "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/Images/small.png" "--blur" "Median" "3" "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/build/output/blur3.png")
set_tests_properties([=[BlurMedian]=] PROPERTIES  TIMEOUT "10" _BACKTRACE_TRIPLES "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/cmdtests.cmake;18;add_test;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/cmdtests.cmake;0;;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/CMakeLists.txt;56;include;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/CMakeLists.txt;0;")
add_test([=[EdgeSobel]=] "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/build/APImageFilters" "-i" "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/Images/small.png" "--edge" "Sobel" "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/build/output/edge1.png")
set_tests_properties([=[EdgeSobel]=] PROPERTIES  TIMEOUT "10" _BACKTRACE_TRIPLES "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/cmdtests.cmake;19;add_test;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/cmdtests.cmake;0;;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/CMakeLists.txt;56;include;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/CMakeLists.txt;0;")
add_test([=[EdgePrewitt]=] "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/build/APImageFilters" "-i" "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/Images/small.png" "--edge" "Prewitt" "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/build/output/edge2.png")
set_tests_properties([=[EdgePrewitt]=] PROPERTIES  TIMEOUT "10" _BACKTRACE_TRIPLES "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/cmdtests.cmake;20;add_test;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/cmdtests.cmake;0;;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/CMakeLists.txt;56;include;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/CMakeLists.txt;0;")
add_test([=[EdgeScharr]=] "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/build/APImageFilters" "-i" "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/Images/small.png" "-e" "Scharr" "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/build/output/edge3.png")
set_tests_properties([=[EdgeScharr]=] PROPERTIES  TIMEOUT "10" _BACKTRACE_TRIPLES "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/cmdtests.cmake;21;add_test;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/cmdtests.cmake;0;;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/CMakeLists.txt;56;include;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/CMakeLists.txt;0;")
add_test([=[EdgeRobertsCross]=] "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/build/APImageFilters" "-i" "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/Images/small.png" "-e" "RobertsCross" "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/build/output/edge4.png")
set_tests_properties([=[EdgeRobertsCross]=] PROPERTIES  TIMEOUT "10" _BACKTRACE_TRIPLES "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/cmdtests.cmake;22;add_test;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/cmdtests.cmake;0;;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/CMakeLists.txt;56;include;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/CMakeLists.txt;0;")
add_test([=[Sharpen1]=] "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/build/APImageFilters" "-i" "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/Images/small.png" "-p" "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/build/output/sharpen1.png")
set_tests_properties([=[Sharpen1]=] PROPERTIES  TIMEOUT "10" _BACKTRACE_TRIPLES "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/cmdtests.cmake;23;add_test;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/cmdtests.cmake;0;;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/CMakeLists.txt;56;include;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/CMakeLists.txt;0;")
add_test([=[Sharpen2]=] "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/build/APImageFilters" "-i" "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/Images/small.png" "--sharpen" "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/build/output/sharpen2.png")
set_tests_properties([=[Sharpen2]=] PROPERTIES  TIMEOUT "10" _BACKTRACE_TRIPLES "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/cmdtests.cmake;24;add_test;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/cmdtests.cmake;0;;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/CMakeLists.txt;56;include;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/CMakeLists.txt;0;")
add_test([=[SaltPepper5]=] "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/build/APImageFilters" "-i" "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/Images/small.png" "--saltpepper" "5" "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/build/output/saltpepper1.png")
set_tests_properties([=[SaltPepper5]=] PROPERTIES  TIMEOUT "10" _BACKTRACE_TRIPLES "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/cmdtests.cmake;25;add_test;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/cmdtests.cmake;0;;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/CMakeLists.txt;56;include;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/CMakeLists.txt;0;")
add_test([=[SaltPepper75]=] "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/build/APImageFilters" "-i" "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/Images/small.png" "-n" "75" "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/build/output/saltpepper2.png")
set_tests_properties([=[SaltPepper75]=] PROPERTIES  TIMEOUT "10" _BACKTRACE_TRIPLES "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/cmdtests.cmake;26;add_test;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/cmdtests.cmake;0;;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/CMakeLists.txt;56;include;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/CMakeLists.txt;0;")
add_test([=[ThresholdHSV128]=] "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/build/APImageFilters" "-i" "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/Images/small.png" "--threshold" "128" "HSV" "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/build/output/threshold1.png")
set_tests_properties([=[ThresholdHSV128]=] PROPERTIES  TIMEOUT "10" _BACKTRACE_TRIPLES "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/cmdtests.cmake;27;add_test;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/cmdtests.cmake;0;;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/CMakeLists.txt;56;include;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/CMakeLists.txt;0;")
add_test([=[ThresholdHSL64]=] "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/build/APImageFilters" "-i" "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/Images/small.png" "-t" "64" "HSL" "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/build/output/threshold2.png")
set_tests_properties([=[ThresholdHSL64]=] PROPERTIES  TIMEOUT "10" _BACKTRACE_TRIPLES "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/cmdtests.cmake;28;add_test;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/cmdtests.cmake;0;;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/CMakeLists.txt;56;include;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/CMakeLists.txt;0;")
add_test([=[MultiFilter]=] "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/build/APImageFilters" "-i" "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/Images/small.png" "-b" "100" "-g" "-r" "Gaussian" "5" "1.0" "-e" "Sobel" "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/build/output/multifilter.png")
set_tests_properties([=[MultiFilter]=] PROPERTIES  TIMEOUT "60" _BACKTRACE_TRIPLES "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/cmdtests.cmake;29;add_test;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/cmdtests.cmake;0;;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/CMakeLists.txt;56;include;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/CMakeLists.txt;0;")
add_test([=[SliceXZ]=] "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/build/APImageFilters" "-d" "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/Scans/TestVolume/vol" "-s" "XZ" "16" "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/build/output/sliceXZ.png")
set_tests_properties([=[SliceXZ]=] PROPERTIES  TIMEOUT "60" _BACKTRACE_TRIPLES "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/cmdtests.cmake;55;add_test;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/cmdtests.cmake;0;;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/CMakeLists.txt;56;include;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/CMakeLists.txt;0;")
add_test([=[SliceYZ]=] "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/build/APImageFilters" "-d" "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/Scans/TestVolume/vol" "--slice" "YZ" "16" "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/build/output/sliceYZ.png")
set_tests_properties([=[SliceYZ]=] PROPERTIES  TIMEOUT "60" _BACKTRACE_TRIPLES "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/cmdtests.cmake;56;add_test;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/cmdtests.cmake;0;;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/CMakeLists.txt;56;include;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/CMakeLists.txt;0;")
add_test([=[ProjectionMIP]=] "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/build/APImageFilters" "-d" "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/Scans/TestVolume/vol" "-p" "MIP" "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/build/output/projectionMIP.png")
set_tests_properties([=[ProjectionMIP]=] PROPERTIES  TIMEOUT "60" _BACKTRACE_TRIPLES "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/cmdtests.cmake;57;add_test;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/cmdtests.cmake;0;;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/CMakeLists.txt;56;include;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/CMakeLists.txt;0;")
add_test([=[ProjectionMinIP]=] "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/build/APImageFilters" "-d" "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/Scans/TestVolume/vol" "--projection" "MinIP" "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/build/output/projectionMinIP.png")
set_tests_properties([=[ProjectionMinIP]=] PROPERTIES  TIMEOUT "60" _BACKTRACE_TRIPLES "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/cmdtests.cmake;58;add_test;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/cmdtests.cmake;0;;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/CMakeLists.txt;56;include;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/CMakeLists.txt;0;")
add_test([=[ProjectionMeanAIP]=] "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/build/APImageFilters" "-d" "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/Scans/TestVolume/vol" "-p" "meanAIP" "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/build/output/projectionMeanAIP.png")
set_tests_properties([=[ProjectionMeanAIP]=] PROPERTIES  TIMEOUT "60" _BACKTRACE_TRIPLES "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/cmdtests.cmake;59;add_test;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/cmdtests.cmake;0;;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/CMakeLists.txt;56;include;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/CMakeLists.txt;0;")
add_test([=[ProjectionMedianAIP]=] "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/build/APImageFilters" "-d" "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/Scans/TestVolume/vol" "-p" "medianAIP" "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/build/output/projectionMedianAIP.png")
set_tests_properties([=[ProjectionMedianAIP]=] PROPERTIES  TIMEOUT "60" _BACKTRACE_TRIPLES "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/cmdtests.cmake;60;add_test;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/cmdtests.cmake;0;;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/CMakeLists.txt;56;include;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/CMakeLists.txt;0;")
add_test([=[SliceXZGaussian]=] "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/build/APImageFilters" "-d" "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/Scans/TestVolume/vol" "-r" "Gaussian" "3" "2.0" "-s" "XZ" "16" "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/build/output/sliceXZGaussian.png")
set_tests_properties([=[SliceXZGaussian]=] PROPERTIES  TIMEOUT "120" _BACKTRACE_TRIPLES "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/cmdtests.cmake;63;add_test;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/cmdtests.cmake;0;;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/CMakeLists.txt;56;include;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/CMakeLists.txt;0;")
add_test([=[SliceYZMedian]=] "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/build/APImageFilters" "-d" "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/Scans/TestVolume/vol" "--blur" "Median" "3" "--slice" "YZ" "16" "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/build/output/sliceYZMedian.png")
set_tests_properties([=[SliceYZMedian]=] PROPERTIES  TIMEOUT "120" _BACKTRACE_TRIPLES "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/cmdtests.cmake;65;add_test;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/cmdtests.cmake;0;;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/CMakeLists.txt;56;include;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/CMakeLists.txt;0;")
add_test([=[ProjectionMIPGaussian]=] "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/build/APImageFilters" "-d" "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/Scans/TestVolume/vol" "-r" "Gaussian" "3" "1.0" "-p" "MIP" "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/build/output/projectionMIPGaussian.png")
set_tests_properties([=[ProjectionMIPGaussian]=] PROPERTIES  TIMEOUT "120" _BACKTRACE_TRIPLES "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/cmdtests.cmake;67;add_test;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/cmdtests.cmake;0;;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/CMakeLists.txt;56;include;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/CMakeLists.txt;0;")
add_test([=[ProjectionMinIPMedian]=] "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/build/APImageFilters" "-d" "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/Scans/TestVolume/vol" "--blur" "Median" "3" "--projection" "MIP" "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/build/output/projectionMIPMedian.png")
set_tests_properties([=[ProjectionMinIPMedian]=] PROPERTIES  TIMEOUT "120" _BACKTRACE_TRIPLES "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/cmdtests.cmake;69;add_test;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/cmdtests.cmake;0;;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/CMakeLists.txt;56;include;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/CMakeLists.txt;0;")
add_test([=[ThinSlabSliceXZ]=] "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/build/APImageFilters" "-d" "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/Scans/TestVolume/vol" "-f" "4" "-l" "28" "-s" "XZ" "16" "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/build/output/sliceXZthinslab.png")
set_tests_properties([=[ThinSlabSliceXZ]=] PROPERTIES  TIMEOUT "60" _BACKTRACE_TRIPLES "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/cmdtests.cmake;73;add_test;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/cmdtests.cmake;0;;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/CMakeLists.txt;56;include;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/CMakeLists.txt;0;")
add_test([=[ThinSlabSliceYZ]=] "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/build/APImageFilters" "-d" "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/Scans/TestVolume/vol" "--first" "4" "--last" "28" "-s" "YZ" "16" "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/build/output/sliceYZthinslab.png")
set_tests_properties([=[ThinSlabSliceYZ]=] PROPERTIES  TIMEOUT "60" _BACKTRACE_TRIPLES "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/cmdtests.cmake;75;add_test;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/cmdtests.cmake;0;;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/CMakeLists.txt;56;include;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/CMakeLists.txt;0;")
add_test([=[ThinSlabProjectionMIP]=] "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/build/APImageFilters" "-d" "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/Scans/TestVolume/vol" "-f" "4" "-l" "28" "-p" "MIP" "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/build/output/projectionMIPthinslab.png")
set_tests_properties([=[ThinSlabProjectionMIP]=] PROPERTIES  TIMEOUT "60" _BACKTRACE_TRIPLES "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/cmdtests.cmake;77;add_test;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/cmdtests.cmake;0;;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/CMakeLists.txt;56;include;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/CMakeLists.txt;0;")
add_test([=[ThinSlabProjectionMinIP]=] "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/build/APImageFilters" "-d" "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/Scans/TestVolume/vol" "--first" "4" "--last" "28" "--projection" "MinIP" "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/build/output/projectionMinIPthinslab.png")
set_tests_properties([=[ThinSlabProjectionMinIP]=] PROPERTIES  TIMEOUT "60" _BACKTRACE_TRIPLES "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/cmdtests.cmake;79;add_test;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/cmdtests.cmake;0;;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/CMakeLists.txt;56;include;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/CMakeLists.txt;0;")
add_test([=[ThinSlabSliceXZGaussian]=] "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/build/APImageFilters" "-d" "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/Scans/TestVolume/vol" "-f" "4" "-l" "28" "-r" "Gaussian" "3" "2.0" "-s" "XZ" "16" "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/build/output/sliceXZGaussianthinslab.png")
set_tests_properties([=[ThinSlabSliceXZGaussian]=] PROPERTIES  TIMEOUT "120" _BACKTRACE_TRIPLES "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/cmdtests.cmake;81;add_test;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/cmdtests.cmake;0;;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/CMakeLists.txt;56;include;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/CMakeLists.txt;0;")
add_test([=[ThinSlabProjectMIPMedian]=] "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/build/APImageFilters" "-d" "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/Scans/TestVolume/vol" "--first" "4" "--last" "28" "-r" "Median" "3" "-p" "MIP" "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/build/output/projectionMIPMedianthinslab.png")
set_tests_properties([=[ThinSlabProjectMIPMedian]=] PROPERTIES  TIMEOUT "120" _BACKTRACE_TRIPLES "/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/cmdtests.cmake;83;add_test;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/cmdtests.cmake;0;;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/CMakeLists.txt;56;include;/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/CMakeLists.txt;0;")
