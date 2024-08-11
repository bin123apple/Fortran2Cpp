program test_great_relations
    implicit none
    
    ! Declare a type for relationships
    type :: Relationship
        character(len=10) :: from
        character(len=10) :: to
    end type Relationship
    
    ! Declare an array of relationships
    type(Relationship), parameter :: relationships(39) = [Relationship("i1", "x1"),  &
        Relationship("c1", "a1"), Relationship("a1", "o1"), Relationship("j1", "aa1"), &
        Relationship("h1", "l1"), Relationship("ii1", "ff1"), Relationship("bb1", "x1"), &
        Relationship("h1", "t1"), Relationship("cc1", "dd1"), Relationship("ff1", "u1"), &
        Relationship("ii1", "s1"), Relationship("v1", "ee1"), Relationship("g1", "b1"), &
        Relationship("d1", "k1"), Relationship("ff1", "ll1"), Relationship("r1", "bb1"), &
        Relationship("ii1", "m1"), Relationship("u1", "p1"), Relationship("hh1", "l1"), &
        Relationship("g1", "o1"), Relationship("ii1", "o1"), Relationship("z1", "j1"), &
        Relationship("y1", "w1"), Relationship("ff1", "bb1"), Relationship("cc1", "s1"), &
        Relationship("j1", "cc1"), Relationship("hh1", "ee1"), Relationship("cc1", "ll1"), &
        Relationship("u1", "x1"), Relationship("u1", "v1"), Relationship("f1", "ee1"), &
        Relationship("d1", "ff1"), Relationship("hh1", "k1"), Relationship("d1", "t1"), &
        Relationship("aa1", "n1"), Relationship("jj1", "x1"), Relationship("k1", "cc1"), &
        Relationship("ee1", "aa1"), Relationship("z1", "g1")]

    ! Testing the relationships
    call test_relationship("i1", "x1")
    call test_relationship("cc1", "dd1")
    ! Add more tests as needed
    ! A test for a non-existing relationship
    call test_relationship("i1", "dd1")

contains

    subroutine test_relationship(from, to)
        character(len=*), intent(in) :: from, to
        logical :: result
        
        result = check_relationship(from, to)
        
        if (result) then
            print *, "Relationship between", from, "and", to, "exists."
        else
            print *, "Relationship between", from, "and", to, "does not exist."
        end if
    end subroutine test_relationship
    
    function check_relationship(from, to) result(is_great)
        character(len=*), intent(in) :: from, to
        logical :: is_great
        integer :: i
        
        is_great = .false.
        
        ! Check if the relationship exists
        do i = 1, size(relationships)
            if (trim(relationships(i)%from) == trim(from) .and. &
                trim(relationships(i)%to) == trim(to)) then
                is_great = .true.
                exit
            end if
        end do
        
    end function check_relationship

end program test_great_relations