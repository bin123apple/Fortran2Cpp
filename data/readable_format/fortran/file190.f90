module Block_File_Names
    implicit none
    character(len=200) :: inPrefix
    character(len=200) :: outPrefix
    character(len=200) :: Flow_File
    character(len=200) :: Heat_File
    character(len=200) :: Init_File
    character(len=200) :: Net_File
    character(len=200) :: NPS_File
    character(len=200) :: Param_File
    character(len=200) :: Source_File
    character(len=200) :: Spatial_File
end module Block_File_Names

program test_block_file_names
    use Block_File_Names
    implicit none

    ! Instantiate the module variables
    inPrefix = 'input_'
    outPrefix = 'output_'
    Flow_File = 'flow.dat'
    Heat_File = 'heat.dat'
    Init_File = 'init.dat'
    Net_File = 'net.dat'
    NPS_File = 'nps.dat'
    Param_File = 'param.dat'
    Source_File = 'source.dat'
    Spatial_File = 'spatial.dat'

    ! Simple check for inPrefix
    if (inPrefix == 'input_') then
        print *, 'Test passed for inPrefix'
    else
        print *, 'Test failed for inPrefix'
    endif

    ! You can add similar checks for other variables if needed
end program test_block_file_names