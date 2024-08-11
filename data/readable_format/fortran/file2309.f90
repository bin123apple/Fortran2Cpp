module mock_xmp
    implicit none
contains
    function xmp_num_nodes() result(num_nodes)
        integer :: num_nodes
        num_nodes = 4
    end function xmp_num_nodes

    function xmp_node_num() result(node_num)
        integer :: node_num
        node_num = 1
    end function xmp_node_num
end module mock_xmp

program test_main
    use mock_xmp
    implicit none
    integer :: i

    do i = 1, xmp_num_nodes()
        call main(i)
    end do
end program test_main

subroutine main(mock_node)
    use mock_xmp
    implicit none
    integer, intent(in) :: mock_node
    integer :: procs, id
    integer :: mask1, val1
    integer :: mask2, val2
    logical :: l1, l2
    character(len=2) :: result
    integer :: i

    if(xmp_num_nodes() > 31) then
        print *, 'You have to run this program by less than 32 nodes.'
        return
    endif

    procs = xmp_num_nodes()
    id = mock_node - 1
    result = 'OK'

    do i = 0, 2**procs - 1, 2
        mask1 = ishft(1, id)
        val1 = iand(i, mask1)
        l1 = (val1 /= 0)

        mask2 = ishft(1, id)
        val2 = iand(i+1, mask2)
        l2 = (val2 /= 0)

        if (l1) result = 'NG'
        if (i+1 == 2**procs - 1) then
            if (.not. l2) result = 'NG'
        else
            if (l2) result = 'NG'
        endif
    end do

    print *, mock_node, 'test ', result
end subroutine main