program TestElemEdgeNeighbor
    implicit none
    integer, dimension(2,2) :: ElemConnectivity
    integer :: ElemId1, ElemEdge1, ElemId2, ElemEdge2
    logical :: bflag

    ! Initialize test data
    ElemConnectivity = reshape([1, 2, 3, 4], shape(ElemConnectivity))
    ElemId1 = 1
    ElemEdge1 = 1

    ! Test the first subroutine
    call FindElemEdgeNeighbor(ElemConnectivity, ElemId1, ElemEdge1, bflag, ElemId2, ElemEdge2)
    print *, "After FindElemEdgeNeighbor:"
    print *, "bflag:", bflag, "ElemId2:", ElemId2, "ElemEdge2:", ElemEdge2

    ! Test the second subroutine
    call FindElemEdgeNeighbor2(ElemConnectivity, ElemId1, ElemEdge1, bflag, ElemId2, ElemEdge2)
    print *, "After FindElemEdgeNeighbor2:"
    print *, "bflag:", bflag, "ElemId2:", ElemId2, "ElemEdge2:", ElemEdge2

contains

    subroutine FindElemEdgeNeighbor(ElemConnectivity, ElemId1, ElemEdge1, bflag, ElemId2, ElemEdge2)
        integer, intent(in) :: ElemConnectivity(:,:)
        integer, intent(in) :: ElemId1, ElemEdge1
        logical, intent(out) :: bflag
        integer, intent(out) :: ElemId2, ElemEdge2

        ! Implement the subroutine logic here
        bflag = .false.
        ElemId2 = ElemId1 + 1
        ElemEdge2 = ElemEdge1 + 1
    end subroutine FindElemEdgeNeighbor

    subroutine FindElemEdgeNeighbor2(ElemConnectivity, ElemId1, ElemEdge1, bflag, ElemId2, ElemEdge2)
        integer, intent(in) :: ElemConnectivity(:,:)
        integer, intent(in) :: ElemId1, ElemEdge1
        logical, intent(out) :: bflag
        integer, intent(out) :: ElemId2, ElemEdge2

        ! Implement the subroutine logic here
        bflag = .true.
        ElemId2 = ElemId1 - 1
        ElemEdge2 = ElemEdge1 - 1
    end subroutine FindElemEdgeNeighbor2

end program TestElemEdgeNeighbor