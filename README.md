THERE ARE 4 MAIN FOLDERS :==
src/ - contains main file for testing
impl/ - actual implementation for "number" (is a library and needs Forward Declartion and linking to be used)
include/ - contains header files (which contains Forward Declartions)
alloc/ - has some faster(i think) way to allocating memory (also a library but is only linked to impl's library not src's executable)



TO COMPILE AND RUN THIS PROJECT:-
1) make a build directory.
2) have cmake installed.
3) go inside build dir. and run "cmake .. && cmake --build ." .
4) now you have a executable called "exe" in the build folder.

BONUS) to use number data type you must use the src folder for your c files and must include "number.h", see inside "number.h" for usefull functions to use.
