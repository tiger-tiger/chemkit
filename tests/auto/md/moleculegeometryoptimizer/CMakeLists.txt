qt4_wrap_cpp(MOC_SOURCES moleculegeometryoptimizertest.h)
add_executable(moleculegeometryoptimizertest moleculegeometryoptimizertest.cpp ${MOC_SOURCES})
target_link_libraries(moleculegeometryoptimizertest chemkit chemkit-md ${QT_LIBRARIES})
add_chemkit_test(md.MoleculeGeometryOptimizer moleculegeometryoptimizertest)
