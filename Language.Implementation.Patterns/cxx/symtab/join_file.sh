file_list=(
BaseScope.hpp
build_by_cmake.sh
BuiltInTypeSymbol.hpp
CMakeLists.txt
Cymbol.g4
DefRefPhase.hpp
gen.sh
GlobalScope.hpp
LocalScope.hpp
MethodSymbol.hpp
Printable.hpp
ScopedSymbol.hpp
Scope.hpp
StructSymbol.hpp
Symbol.hpp
SymbolTable.hpp
t2.cymbol
t2.result
t.cymbol
Test.cpp
t.result
Type.hpp
VariableSymbol.hpp
)

for file in ${file_list[@]}
do
  echo "$file如下:"
  cat $file
  echo ""
done
