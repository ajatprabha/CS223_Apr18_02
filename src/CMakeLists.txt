project(CBS_SRC)

add_executable(CBS main.cpp init.h init.cpp base/models.h base/models.cpp base/views.h base/views.cpp admin/models.h admin/models.cpp users/models.h users/models.cpp controller.h controller.cpp base/exceptions.cpp base/exceptions.h base/mixins.cpp base/mixins.h base/forms.cpp base/forms.h)