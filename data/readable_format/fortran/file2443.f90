module linked_node_mod
  implicit none
  private
  public :: linked_node

  type, abstract :: linked_node
    integer :: id = 0
  end type linked_node

end module linked_node_mod

module bidir_node_mod
  use linked_node_mod, only: linked_node
  implicit none
  private
  public :: bidir_node

  type, extends(linked_node) :: bidir_node
    class(bidir_node), pointer :: prev => null()
  contains
    procedure :: has_prev
    procedure :: get_prev
    procedure :: set_prev
    procedure :: unset_prev
  end type bidir_node

contains

  elemental logical function has_prev(this)
    class(bidir_node), intent(in) :: this
    has_prev = associated(this%prev)
  end function has_prev

  function get_prev(this) result(res)
    class(bidir_node), intent(in) :: this
    class(bidir_node), pointer :: res
    if (this%has_prev()) then
      res => this%prev
    else
      nullify(res)
    end if
  end function get_prev

  subroutine set_prev(this, new_prev, deallocate_old)
    class(bidir_node), intent(inout) :: this
    class(bidir_node), pointer, intent(in) :: new_prev
    logical, optional, intent(in) :: deallocate_old
    call this%unset_prev(deallocate_old)
    this%prev => new_prev
  end subroutine set_prev

  subroutine unset_prev(this, deallocate_old)
    class(bidir_node), intent(inout) :: this
    logical, optional, intent(in) :: deallocate_old
    if (.not. this%has_prev()) return
    if (present(deallocate_old)) then
      if (deallocate_old) then
        if (associated(this%prev)) then
          call this%prev%unset_prev(.true.)
          deallocate(this%prev)
        end if
        return
      end if
    end if
    nullify(this%prev)
  end subroutine unset_prev

end module bidir_node_mod

program test_bidir_node
  use bidir_node_mod
  implicit none

  type(bidir_node), pointer :: node1, node2
  class(bidir_node), pointer :: prevNode

  ! Allocate the nodes
  allocate(node1)
  allocate(node2)
  
  node1%id = 1
  node2%id = 2

  print *, "Node 1 ID:", node1%id
  print *, "Node 2 ID:", node2%id

  ! Test setting and checking the previous node
  call node1%set_prev(node2)
  print *, "Does Node 1 have a previous node?", node1%has_prev()

  if (node1%has_prev()) then
    prevNode => node1%get_prev()
    print *, "Node 1's previous node ID:", prevNode%id
  endif

  ! Test unset_prev
  call node1%unset_prev()
  print *, "Does Node 1 have a previous node after unset?", node1%has_prev()

  ! Deallocate the nodes
  deallocate(node1)
  deallocate(node2)

end program test_bidir_node