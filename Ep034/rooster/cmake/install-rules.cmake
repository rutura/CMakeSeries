install(
    TARGETS Rooster_exe
    RUNTIME COMPONENT Rooster_Runtime
)

if(PROJECT_IS_TOP_LEVEL)
  include(CPack)
endif()
