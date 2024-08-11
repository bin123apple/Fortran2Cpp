! Define the module and all types within
module nt_TypesModule
    implicit none

    type nt_Synapse
        real :: weight
        real :: delta
    end type nt_Synapse

    type nt_Neuron
        type(nt_Synapse), dimension(:), allocatable :: synapses
        integer :: nextLayerSize
        real :: output
        integer :: id
    end type nt_Neuron

    type nt_Layer
        integer :: id
        integer :: layerSize
        type(nt_Neuron), dimension(:), allocatable :: neurons
    end type nt_Layer

    type nt_Net
        integer :: numberOfLayers
        integer, dimension(:), allocatable :: topology
        type(nt_Layer), dimension(:), allocatable :: layers
    end type nt_Net

end module nt_TypesModule

! Define the program that uses the types defined in the module
program TestNtTypesModule
    use nt_TypesModule
    implicit none

    type(nt_Net) :: net

    ! Initialize the net
    net%numberOfLayers = 3
    allocate(net%topology(3))
    net%topology = (/ 2, 3, 1 /)
    allocate(net%layers(3))

    ! Initialize each layer
    net%layers(1)%id = 1
    net%layers(1)%layerSize = 2
    allocate(net%layers(1)%neurons(2))

    net%layers(2)%id = 2
    net%layers(2)%layerSize = 3
    allocate(net%layers(2)%neurons(3))

    net%layers(3)%id = 3
    net%layers(3)%layerSize = 1
    allocate(net%layers(3)%neurons(1))

    ! Print out some values to verify
    print *, "Net number of layers:", net%numberOfLayers
    print *, "Net topology:", net%topology
    print *, "Layer 1 size:", net%layers(1)%layerSize
    print *, "Layer 2 size:", net%layers(2)%layerSize
    print *, "Layer 3 size:", net%layers(3)%layerSize

end program TestNtTypesModule