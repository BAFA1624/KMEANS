file(REMOVE_RECURSE
  "libDataStructs.a"
  "libDataStructs.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/DataStructs.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
