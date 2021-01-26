import os
from conans import ConanFile, CMake, tools


class ConanRecipe(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "cmake_find_package_multi"

    def cmake_setup(self):
        cmake = CMake(self)
        cmake.configure()
        return cmake

    def build(self):
        cmake = self.cmake_setup()
        cmake.build()

    def test(self):
        if not tools.cross_building(self.settings):
            self.run("./test_package")
        else:
            print("Cross compiling, can't run test_package executable, linking successfull")