from conans import ConanFile, CMake, tools


class CXXProjectConan(ConanFile):
    name = "cpp_project"
    version = "1.0.0"
    license = "MIT License"
    author = "Albert Havnegjerde alberthavnegjerde@gmail.com"
    url = "https://github.com/Portfence/cpp_project.git"
    description = "Example of a CXX Project using cmake_find_package_multi generator"
    settings = "os", "compiler", "build_type", "arch"
    requires = "doctest/2.3.4@bincrafters/stable", \
               "trompeloeil/v38@rollbear/stable", \
               "fmt/6.0.0", \
               "plog/1.1.5"
    generators = "cmake_find_package_multi"
    scm = {
        "type": "git",
        "url": url,
        "revision": "auto"
    }


    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()


    def package(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.install()


    def package_info(self):
        if not self.in_local_cache:
            self.cpp_info.includedirs = ["include"]
            self.cpp_info.libdirs = ["build/src"]

        self.cpp_info.libs = [self.name]
