################################################################################
# Package: PrPixel
################################################################################
gaudi_subdir(PrPixel v1r10)

gaudi_depends_on_subdirs(Det/VPDet
                         Event/DAQEvent
                         Event/DigiEvent
                         Event/TrackEvent
                         Pr/PrKernel
                         GaudiAlg
                         GaudiKernel)


gaudi_add_module(PrPixel
                 src/*.cpp
                 INCLUDE_DIRS AIDA GSL Pr/PrKernel
		 LINK_LIBRARIES VPDetLib DAQEventLib TrackEvent GaudiAlgLib GaudiKernel )



