# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file LICENSE.rst or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION ${CMAKE_VERSION}) # this file comes with cmake

# If CMAKE_DISABLE_SOURCE_CHANGES is set to true and the source directory is an
# existing directory in our source tree, calling file(MAKE_DIRECTORY) on it
# would cause a fatal error, even though it would be a no-op.
if(NOT EXISTS "C:/DMU/Game Programming/Year 2/GAMR2541/angry-birds-clone-assignment-NE12follow1/Build/_deps/sfml-src")
  file(MAKE_DIRECTORY "C:/DMU/Game Programming/Year 2/GAMR2541/angry-birds-clone-assignment-NE12follow1/Build/_deps/sfml-src")
endif()
file(MAKE_DIRECTORY
  "C:/DMU/Game Programming/Year 2/GAMR2541/angry-birds-clone-assignment-NE12follow1/Build/_deps/sfml-build"
  "C:/DMU/Game Programming/Year 2/GAMR2541/angry-birds-clone-assignment-NE12follow1/Build/_deps/sfml-subbuild/sfml-populate-prefix"
  "C:/DMU/Game Programming/Year 2/GAMR2541/angry-birds-clone-assignment-NE12follow1/Build/_deps/sfml-subbuild/sfml-populate-prefix/tmp"
  "C:/DMU/Game Programming/Year 2/GAMR2541/angry-birds-clone-assignment-NE12follow1/Build/_deps/sfml-subbuild/sfml-populate-prefix/src/sfml-populate-stamp"
  "C:/DMU/Game Programming/Year 2/GAMR2541/angry-birds-clone-assignment-NE12follow1/Build/_deps/sfml-subbuild/sfml-populate-prefix/src"
  "C:/DMU/Game Programming/Year 2/GAMR2541/angry-birds-clone-assignment-NE12follow1/Build/_deps/sfml-subbuild/sfml-populate-prefix/src/sfml-populate-stamp"
)

set(configSubDirs Debug)
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/DMU/Game Programming/Year 2/GAMR2541/angry-birds-clone-assignment-NE12follow1/Build/_deps/sfml-subbuild/sfml-populate-prefix/src/sfml-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "C:/DMU/Game Programming/Year 2/GAMR2541/angry-birds-clone-assignment-NE12follow1/Build/_deps/sfml-subbuild/sfml-populate-prefix/src/sfml-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
