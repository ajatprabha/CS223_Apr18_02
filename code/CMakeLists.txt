
include_directories(base)
link_directories(base)
add_subdirectory(base)

set( CBS_SOURCES main.cpp admin/forms/UserCreateUpdateForm.cpp admin/forms/UserCreateUpdateForm.h
        admin/forms/RoomCreateUpdateForm.cpp admin/forms/RoomCreateUpdateForm.h users/models/Professor.cpp
        users/models/Professor.h users/models/Admin.cpp users/models/Admin.h users/views/LoginView.cpp
        users/views/LoginView.h users/views/LogoutView.cpp users/views/LogoutView.h users/views/UserCreateView.cpp
        users/views/UserCreateView.h users/views/UserUpdateView.cpp users/views/UserUpdateView.h
        admin/views/AdminPanelView.cpp admin/views/AdminPanelView.h admin/views/AdminDetailView.cpp
        admin/views/AdminDetailView.h admin/views/UnseenSlotRequestListView.cpp admin/views/UnseenSlotRequestListView.h
        users/views/UserDeleteView.cpp users/views/UserDeleteView.h admin/views/RoomCreateView.cpp
        admin/views/RoomCreateView.h admin/views/RoomDetailView.cpp admin/views/RoomDetailView.h
        admin/views/RoomUpdateView.cpp admin/views/RoomUpdateView.h booking/models/Room.cpp booking/models/Room.h
        booking/models/Slot.cpp booking/models/Slot.h booking/forms/SlotCreateUpdateForm.cpp
        booking/forms/SlotCreateUpdateForm.h booking/views/FacultyPanelView.cpp booking/views/FacultyPanelView.h
        booking/views/EmptyRoomListView.cpp booking/views/EmptyRoomListView.h booking/views/SlotCreateView.cpp
        booking/views/SlotCreateView.h booking/views/SlotUpdateView.cpp booking/views/SlotUpdateView.h
        booking/views/SlotNotificationListView.cpp booking/views/SlotNotificationListView.h
        init/Application.cpp init/Application.h init/views/SplashView.cpp init/views/SplashView.h admin/views/RoomDeleteView.cpp admin/views/RoomDeleteView.h booking/views/SlotDeleteView.cpp booking/views/SlotDeleteView.h)

add_executable(${PROJECT_NAME} ${CBS_SOURCES})

target_link_libraries(${PROJECT_NAME} BaseLib)