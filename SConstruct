from os.path import join

srcDir = "src"
testDir = "test"
programPath = "bin"
programName = "attributor"

env = Environment(CC = "g++")
env.Append(CPPFLAGS='-std=c++0x -g')
env.Append(CPPPATH=srcDir)
# Do everything else

sources = Glob(join(srcDir, "*.cpp"))

print join(testDir, "*.cpp")

# Build all modules within the source directory
objects = []
for src in sources:
    objects += env.Object(src)


# Compile the remaining source files and create a program using the above libs
objects = objects + env.Object(Glob(join(testDir, '*.cpp')))

env.Program(join(programPath, programName), objects)