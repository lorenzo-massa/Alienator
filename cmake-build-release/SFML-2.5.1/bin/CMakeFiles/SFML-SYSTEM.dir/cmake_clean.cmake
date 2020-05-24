file(REMOVE_RECURSE
  "libSFML-SYSTEM.a"
  "libSFML-SYSTEM.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/SFML-SYSTEM.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
