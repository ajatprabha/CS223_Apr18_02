ADD_LIBRARY( BaseLib STATIC
        controller.cpp exceptions/Exception.cpp exceptions/NotImplementedError.cpp forms/Form.cpp forms/ModelForm.cpp
        mixins/MultipleObjectMixin.cpp mixins/SingleObjectMixin.cpp models/BaseUser.cpp models/Model.cpp
        utils/DateTime.cpp utils/Input.cpp utils/ViewPattern.cpp views/View.cpp views/DetailView.cpp
        views/DeleteView.cpp views/UpdateView.cpp views/CreateView.cpp views/ListView.cpp utils/Context.cpp utils/Context.h utils/Response.cpp utils/Response.h)