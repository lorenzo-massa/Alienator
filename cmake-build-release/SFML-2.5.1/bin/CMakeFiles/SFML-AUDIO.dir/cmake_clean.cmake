file(REMOVE_RECURSE
  "libSFML-AUDIO.a"
  "libSFML-AUDIO.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/SFML-AUDIO.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
