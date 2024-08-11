program test_edg
    implicit none
    integer :: l, k, result
    integer, dimension(3, 3) :: e

    ! Initialize test data
    e = reshape([1, 2, 3, 4, 5, 6, 7, 8, 9], shape(e))
    
    ! Test case 1: adjacent elements
    l = 1
    k = 4
    result = edg(l, k, e)
    print *, 'Test Case 1 Result:', result

    ! Test case 2: non-adjacent elements
    l = 2
    k = 10
    result = edg(l, k, e)
    print *, 'Test Case 2 Result:', result

contains

    function edg(l,k,e)
        implicit none
        integer l,k,i,e(3,*),edg
        do 10 i=1,3
            if(e(i,l).eq.k) then
                edg=i
                return
            end if
    10   continue
        write(6,'("0***error in function edg***")')
        write(6,'("***elements not adjacent***")')
        call exit(201)
    end function edg

end program test_edg