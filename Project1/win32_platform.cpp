#include <windows.h>

LRESULT CALLBACK window_callback(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nShowCmd) {
    // Create Window Class
    WNDCLASS window_class = {};
    window_class.style = CS_HREDRAW | CS_VREDRAW;
    window_class.lpszClassName = L"GameWindowClass";
    window_class.lpfnWndProc = window_callback;

    // Register Class
    if (!RegisterClass(&window_class)) {
        MessageBoxW(NULL, L"Window Registration Failed!", L"Error", MB_ICONERROR);
        return 1;
    }

    // Create Window
    HWND hwnd = CreateWindowW(window_class.lpszClassName, L"My First Game!", WS_OVERLAPPEDWINDOW | WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT, 1280, 720, NULL, NULL, hInstance, NULL);
    if (!hwnd) {
        MessageBoxW(NULL, L"Window Creation Failed!", L"Error", MB_ICONERROR);
        UnregisterClass(window_class.lpszClassName, hInstance);
        return 1;
    }

    // Message Loop
    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    // Unregister Class
    UnregisterClass(window_class.lpszClassName, hInstance);

    return 0;
}
