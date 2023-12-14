install(
    TARGETS rooster_exe
    RUNTIME COMPONENT rooster_Runtime
)

if(PROJECT_IS_TOP_LEVEL)
  include(CPack)
endif()
