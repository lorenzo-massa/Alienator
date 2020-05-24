file(REMOVE_RECURSE
  "libSFML-GRAPHICS.a"
  "libSFML-GRAPHICS.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/SFML-GRAPHICS.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
