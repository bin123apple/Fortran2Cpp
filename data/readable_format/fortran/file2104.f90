! Define the module and variables
module options
    implicit none
    integer :: itheory
    integer :: itheory_xc

    integer :: iharris
    integer :: idogs
    integer :: ihubbard
    integer :: imcweda
    integer :: igsn
    integer :: ihorsfield
    integer :: iks
    integer :: itdse
    integer :: imdet

    integer :: icluster               
    integer :: ifixcharge             
    integer :: ifixneigh              
    integer :: igauss                 
    integer :: iimage                 
    integer :: ipathintegral          
    integer :: iqout                  
    integer :: iquench                
    integer :: ispin                  
    integer :: iensemble              
    integer :: iordern                
    integer :: iumbrella              
    integer :: ivdw                   
    integer :: idynmat                
    integer :: iharmonic              
    integer :: ithermoint             
    integer :: ireducekpts            
    integer :: iendtemp               
    integer :: ineb                   
    integer :: itrans                 
    integer :: igrid                  
    integer :: ibias                  
    integer :: igap                   
    integer :: icDFT                  
    integer :: iProjWF                
    integer :: iqmmm                  
    integer :: mix_embedding
    integer :: iephc                  
    integer :: idftd3                 
    integer :: idipole                
    integer :: isocket                
    integer :: ixczw                  
    integer :: V_intra_dip            

    integer :: iforce
    integer :: imix
    integer :: iclassicMD
    integer :: itestrange
    integer, dimension(4) :: iconstraints             
    integer, dimension(24) :: ioff2c              
    integer, dimension(4) :: ioff3c
    real :: testrange
    real :: cut_embedding          
    real :: dftd3_s6, dftd3_rs6, dftd3_s18, dftd3_rs18, dftd3_alp
    character(len=40) :: dftd3_func
    integer :: dftd3_version
    logical :: dftd3_tz 
    real, dimension(5) :: dftd3_params
    integer :: verbosity         
    integer :: ntpr         
    integer :: restartxyz 
    integer :: inputxyz 

end module options

! Test program
program test_options
    use options
    implicit none
    
    ! Initialize some variables for testing
    itheory = 1
    itheory_xc = 2
    ! Add initializations for other variables as needed
    
    ! Test by printing out values
    print *, "Testing Fortran module within the same file"
    print *, "itheory should be 1: ", itheory
    print *, "itheory_xc should be 2: ", itheory_xc
    ! Add more print statements as needed for other variables
end program test_options