MODULE collect_info_mod
    IMPLICIT NONE
    TYPE :: collect_info_type
        ! Define members of the type here. For demonstration:
        INTEGER :: dummy
    END TYPE collect_info_type

CONTAINS

    SUBROUTINE collect_the_info(info, use_ph_images, my_image_id, nimage, nqs, nat, irr_iq, inter_image_comm)
        TYPE(collect_info_type), INTENT(INOUT) :: info
        LOGICAL, INTENT(IN) :: use_ph_images
        INTEGER, INTENT(IN) :: my_image_id, nimage, nqs, nat, irr_iq, inter_image_comm
        INTEGER :: pos, nima

        IF (use_ph_images) THEN
            pos = my_image_id + 1
            nima = nimage
        ELSE
            pos = 1
            nima = 1
        ENDIF

        ! Dummy procedures to simulate the actual ones
        CALL init_collect_info(info, nqs, nat, nima, irr_iq)
        CALL save_collect_info(info, nqs, nat, pos, .TRUE., .TRUE., .TRUE., .TRUE.)

        IF (use_ph_images) CALL comm_collect_info(info, inter_image_comm)
    END SUBROUTINE collect_the_info

    SUBROUTINE init_collect_info(info, nqs, nat, nima, irr_iq)
        TYPE(collect_info_type), INTENT(INOUT) :: info
        INTEGER, INTENT(IN) :: nqs, nat, nima, irr_iq
        ! Dummy implementation
    END SUBROUTINE init_collect_info

    SUBROUTINE save_collect_info(info, nqs, nat, pos, comp_irr_iq, done_irr_iq, comp_iq, done_iq)
        TYPE(collect_info_type), INTENT(INOUT) :: info
        INTEGER, INTENT(IN) :: nqs, nat, pos
        LOGICAL, INTENT(IN) :: comp_irr_iq, done_irr_iq, comp_iq, done_iq
        ! Dummy implementation
    END SUBROUTINE save_collect_info

    SUBROUTINE comm_collect_info(info, inter_image_comm)
        TYPE(collect_info_type), INTENT(INOUT) :: info
        INTEGER, INTENT(IN) :: inter_image_comm
        ! Dummy implementation
    END SUBROUTINE comm_collect_info

END MODULE collect_info_mod

PROGRAM test_collect_the_info
    USE collect_info_mod
    IMPLICIT NONE
    TYPE(collect_info_type) :: info
    LOGICAL :: use_ph_images = .FALSE.
    INTEGER :: my_image_id = 0, nimage = 1, nqs = 10, nat = 50, irr_iq = 7, inter_image_comm = 1

    CALL collect_the_info(info, use_ph_images, my_image_id, nimage, nqs, nat, irr_iq, inter_image_comm)
    ! Ideally, here you would check the values inside 'info' to ensure they are what you expect.
    PRINT *, "Test ran successfully"
END PROGRAM test_collect_the_info