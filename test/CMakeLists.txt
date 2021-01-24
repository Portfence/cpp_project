add_executable(test_${PROJECT_NAME} 
    catch.main.cpp
    my_class.test.cpp
    my_other_class.test.cpp
)

target_link_libraries(test_${PROJECT_NAME} 
    PRIVATE
        ${PROJECT_NAME}::${PROJECT_NAME}
        Catch2::Catch2
        trompeloeil
)

add_test(Tester test_${PROJECT_NAME})
