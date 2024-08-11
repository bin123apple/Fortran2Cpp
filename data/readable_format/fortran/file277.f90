module Mod_MBVariables
    implicit none
    ! Declaration of variables
    integer(4)::incp
    
    real(8),dimension(:),allocatable::Nslv,dNslvdxi,dNslv2dxi2
    real(8),dimension(:),allocatable::Mslv,dMslvdeta,dMslv2deta2
    real(8),dimension(:),allocatable::R1
    real(8),dimension(:,:),allocatable::dR1
    real(8),dimension(:,:),allocatable::ddR1
    real(8),dimension(:),allocatable::Rslv,gap
    real(8),dimension(:,:),allocatable::dRslv
    real(8),dimension(:,:),allocatable::ddRslv
    real(8),dimension(:),allocatable::Rmst
    real(8),dimension(:,:),allocatable::dRmst
    real(8),dimension(:,:),allocatable::ddRmst
    integer(4),dimension(:),allocatable::PTS_Active
    
    real(8),dimension(:,:),allocatable::N,Na,Nb,Ta,tb
    real(8),dimension(:,:),allocatable::Nhat,That,D,Nbar
    real(8),dimension(:,:),allocatable::Kgeo,KG1,KG2,KG3,KG4
    
    real(8),dimension(:,:),allocatable::KLM,FLM,GLM
    integer(4),dimension(:),allocatable::disptempLM
    real(8),dimension(:,:),allocatable::KeqLM,FeqLM,DispeqLM
    
    integer(4),dimension(:),allocatable::PTS_conn
end module Mod_MBVariables

program test_Mod_MBVariables
    use Mod_MBVariables
    implicit none

    ! Test initialization and manipulation of some variables
    allocate(Nslv(3), R1(2))
    Nslv = [1.0d0, 2.0d0, 3.0d0]
    R1 = [0.5d0, 1.5d0]

    ! Print to check the values
    print *, 'Nslv:', Nslv
    print *, 'R1:', R1

    ! Test resizing
    allocate(dR1(2, 2), dRslv(2, 3))
    dR1 = reshape([1.0d0, 2.0d0, 3.0d0, 4.0d0], [2, 2])
    dRslv = reshape([0.1d0, 0.2d0, 0.3d0, 0.4d0, 0.5d0, 0.6d0], [2, 3])

    ! Print to check the values
    print *, 'dR1:', dR1
    print *, 'dRslv:', dRslv
end program test_Mod_MBVariables