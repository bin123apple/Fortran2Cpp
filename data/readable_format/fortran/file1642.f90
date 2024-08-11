module particleDefinition
  implicit none
  type :: particle
     ! Assume some properties for particle
     integer :: id
  end type particle
end module particleDefinition

module particlePointerListDefinition
  use particleDefinition, only: particle
  implicit none

  type :: tParticleListNode
     type(particle), pointer :: V => null()
     type(tParticleListNode), pointer :: next => null()
  end type tParticleListNode

  type :: tParticleList
     type(tParticleListNode), pointer :: first => null()
     type(tParticleListNode), pointer :: last => null()
     integer :: nEntries = 0
  end type tParticleList

contains

  subroutine addParticleToList(list, p)
    type(tParticleList), intent(inout) :: list
    type(particle), intent(in) :: p
    type(tParticleListNode), pointer :: newNode

    allocate(newNode)
    allocate(newNode%V)
    newNode%V = p
    newNode%next => null()

    if (.not. associated(list%first)) then
       list%first => newNode
       list%last => newNode
    else
       list%last%next => newNode
       list%last => newNode
    endif
    list%nEntries = list%nEntries + 1
  end subroutine addParticleToList

end module particlePointerListDefinition

program testParticleList
  use particlePointerListDefinition
  implicit none
  type(tParticleList) :: list
  type(particle) :: p1, p2

  p1%id = 1
  p2%id = 2

  call addParticleToList(list, p1)
  call addParticleToList(list, p2)

  print *, "Number of entries in the list: ", list%nEntries
  if (list%nEntries == 2) then
    print *, "Test passed: 2 particles added."
  else
    print *, "Test failed."
  endif

  ! Assuming cleanup routines are defined, you would clean up here
end program testParticleList