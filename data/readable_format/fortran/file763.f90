program test_tam_fijo
    implicit none
    real, dimension(5) :: arreglo_1
    real, dimension(-1:3) :: arreglo_2 = (/1, 2, 3, 4, 5/)
    integer, dimension(5,5) :: matriz
    integer, dimension(0:4) :: arreglo_3
    integer, dimension(0:4, 1:6) :: matriz_2
    integer, dimension(4,4) :: matriz_3

    ! Test initialization of arreglo_2
    if (all(arreglo_2 == (/1, 2, 3, 4, 5/))) then
        print *, "Test passed: arreglo_2 initialization."
    else
        print *, "Test failed: arreglo_2 initialization."
    endif

    ! Test bounds of matriz_2
    matriz_2 = 0
    matriz_2(2, 6) = 10
    if (matriz_2(2, 6) == 10) then
        print *, "Test passed: Accessing bounds of matriz_2."
    else
        print *, "Test failed: Accessing bounds of matriz_2."
    endif

end program test_tam_fijo