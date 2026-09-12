#pragma once
namespace gui {
ref class Theme abstract sealed {
public:
    static void Apply(System::Windows::Forms::Control^ root);
};
}
