file(REMOVE_RECURSE
  "libDataStructs.pdb"
  "libDataStructs.so"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/DataStructs.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
