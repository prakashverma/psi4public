set(headers_list "")
# List of headers
list(APPEND headers_list adc.h )

# If you want to remove some headers specify them explictly here
if(DEVELOPMENT_CODE)
   list(REMOVE_ITEM headers_list "")
else()
   list(REMOVE_ITEM headers_list "")
endif()
# Sort alphabetically
list(SORT headers_list)

set(sources_list "")
# List of sources
list(APPEND sources_list construct_sigma.cc adc_main.cc adc.cc compute_energy.cc differentiation.cc diagonalize.cc amps_write.cc denominator.cc prepare_tensors.cc init_tensors.cc )

# If you want to remove some sources specify them explictly here
if(DEVELOPMENT_CODE)
   list(REMOVE_ITEM sources_list "")
else()
   list(REMOVE_ITEM sources_list "")
endif()

# Write list of files to be passed to cloc for counting lines of code.
# Only files that are actually compiled are counted.
set(to_count "${sources_list}" "${headers_list}")
write_to_cloc_list("${to_count}")

# Build static library
add_library(adc STATIC ${sources_list})
# Specify dependencies for the library (if any)
add_dependencies(adc mints)
set_property(GLOBAL APPEND PROPERTY PSILIB adc)
if(BUILD_CUSTOM_BOOST)
   add_dependencies(adc custom_boost)
endif()

# Sets install directory for all the headers in the list
install_list_FILES("${headers_list}" include/libadc)
