module B8_COM_module
    implicit none
    ! Note: The common block name should not conflict with the module name
    integer :: B8_cm
    real :: B8_nfa
    common /B8_COM_block/ B8_nfa
    equivalence (B8_nfa, B8_cm)
end module B8_COM_module

program testB8
    use B8_COM_module
    implicit none

    ! Demonstrate modifying B8_nfa affects B8_cm
    B8_nfa = 1.0
    print *, 'After setting B8_nfa to 1.0, B8_cm is:', B8_cm

    ! Demonstrate modifying B8_cm affects B8_nfa
    ! Here we use an integer representation that would be equivalent to a float.
    ! The specific value depends on the binary representation of floating-point numbers (IEEE 754).
    ! For simplicity, let's just modify B8_cm and observe changes in B8_nfa without focusing on specific float values.
    B8_cm = 1073741824 
    print *, 'After setting B8_cm to 1073741824, B8_nfa is:', B8_nfa
end program testB8