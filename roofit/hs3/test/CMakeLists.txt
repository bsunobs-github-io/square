ROOT_ADD_GTEST(testRooFitHS3 testRooFitHS3.cxx LIBRARIES RooFitCore RooFit RooFitHS3)
ROOT_ADD_GTEST(testHS3HistFactory testHS3HistFactory.cxx LIBRARIES RooFit RooFitHS3 HistFactory
  COPY_TO_BUILDDIR ${CMAKE_CURRENT_SOURCE_DIR}/test_hs3_histfactory_json_input.root
)
