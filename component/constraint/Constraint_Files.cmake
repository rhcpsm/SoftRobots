
list(APPEND HEADER_FILES

    component/constraint/CableConstraint.h
    component/constraint/CableConstraint.inl

    component/constraint/PartialRigidificationConstraint.h
    component/constraint/PartialRigidificationConstraint.inl

    component/constraint/SurfacePressureConstraint.h
    component/constraint/SurfacePressureConstraint.inl

    component/constraint/UnilateralPlaneConstraint.h
    component/constraint/UnilateralPlaneConstraint.inl

    )

list(APPEND SOURCE_FILES

    component/constraint/CableConstraint.cpp
    component/constraint/PartialRigidificationConstraint.cpp
    component/constraint/SurfacePressureConstraint.cpp
    component/constraint/UnilateralPlaneConstraint.cpp
    )

include(component/constraint/model/Model.cmake)



