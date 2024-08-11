program test_great_relationships
    implicit none
    integer :: num_relationships
    character(len=10), allocatable :: relationships(:,:)

    ! Initialize the number of relationships
    num_relationships = 0
    allocate(relationships(2, 1)) ! Initial allocation

    ! Testing the great subroutine by populating relationships
    call great('JJ1', 'KK1')
    call great('Y1', 'LL1')
    call great('C1', 'Y1')
    ! Add more calls as needed...

    ! After populating relationships, print them to verify
    call print_relationships()

contains

    subroutine great(entity1, entity2)
        character(len=*), intent(in) :: entity1, entity2

        ! Resize the relationships array to accommodate the new relationship
        if (num_relationships > 0) then
            ! Manual reallocation for simplicity
            num_relationships = num_relationships + 1
            call resize_relationships(num_relationships)
        else
            num_relationships = 1
        endif

        ! Store the new relationship
        relationships(1, num_relationships) = entity1
        relationships(2, num_relationships) = entity2
    end subroutine great

    subroutine resize_relationships(new_size)
        integer, intent(in) :: new_size
        character(len=10), allocatable :: temp(:,:)

        ! Allocate a temporary array with the new size and copy existing data
        allocate(temp(2, new_size))
        temp(:, 1:num_relationships) = relationships

        ! Deallocate the old array and move the temporary array
        deallocate(relationships)
        call move_alloc(temp, relationships)
    end subroutine resize_relationships

    subroutine print_relationships()
        integer :: i
        print *, 'Relationships:'
        do i = 1, num_relationships
            print *, trim(relationships(1, i)), '->', trim(relationships(2, i))
        end do
    end subroutine print_relationships

end program test_great_relationships