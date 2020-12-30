file(REMOVE_RECURSE
  "libLoadData.pdb"
  "libLoadData.so"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/LoadData.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
