module node_module
  implicit none
  type :: Node
     integer :: data
     type(Node), pointer :: next => null()
  end type Node

contains

  function add_nodes(node1, node2) result(newNode)
    type(Node), intent(in) :: node1, node2
    type(Node) :: newNode

    newNode%data = node1%data + node2%data
    newNode%next => null()
  end function add_nodes

end module node_module

program test_node_module
  use node_module
  implicit none

  type(Node) :: node1, node2, sumNode

  ! Initialize node data
  node1%data = 10
  node2%data = 20

  ! Perform the operation
  sumNode = add_nodes(node1, node2)

  ! Test the result
  if (sumNode%data == 30) then
    print *, "Test Passed: sumNode%data is 30"
  else
    print *, "Test Failed: sumNode%data is not 30"
  end if

end program test_node_module