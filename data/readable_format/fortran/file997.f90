module treeNodeMod
  implicit none

  type treeNode
  end type treeNode

contains

  subroutine DestroyNode( theNode, lstatus )
    type(treeNode), pointer :: theNode  ! Changed from class to type
    logical, intent(out) :: lstatus
    
    if (associated(theNode)) then
      nullify(theNode)
      lstatus = .true.
    else
      lstatus = .false.
    endif
  end subroutine DestroyNode

end module treeNodeMod

program test
  use treeNodeMod
  implicit none

  type(treeNode), pointer :: theNode => null()
  logical :: lstatus
  
  ! Test DestroyNode with an uninitialized pointer
  call DestroyNode(theNode, lstatus)
  print *, "Test 1 (uninitialized): ", lstatus
  
  ! Initialize and test again
  allocate(theNode)
  call DestroyNode(theNode, lstatus)
  print *, "Test 2 (initialized then destroyed): ", lstatus

end program test