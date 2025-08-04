#include <print>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <imgui/imgui.h>
#include <imgui/imgui_impl_glfw.h>
#include <imgui/imgui_impl_opengl3.h>
#include "types.hpp"
#include "input.hpp"

// window management

GLFWwindow* window;
ImGuiIO io;

ImFont* myFont;

int width = 960;
int height= 540;

// buffers

const size_t bufferSize = 64;

char kmboxIpBuffer  [bufferSize]; 
char kmboxPortBuffer[bufferSize]; 
char kmboxMacBuffer [bufferSize];

// int sliders

int xy_min = -25;
int xy_max = 25;

int x_mv   = 0;
int y_mv   = 0;
int delay  = 0;

int delay_max = 100;

// state management

Mode state = Mode::kmbox;
bool connected = false;

void initBuffers(){
   kmboxIpBuffer  [63]='\0';
   kmboxPortBuffer[63]='\0';
   kmboxMacBuffer [63]='\0';
}

void deviceGUI(){
   ImGui::Begin("[+] Configure mouse movement!");
   if (ImGui::BeginTabBar("MyTabBar")){
      if (ImGui::BeginTabItem("Kmbox ")){
         ImGui::Text("Kmbox here refers the the kmboxnet with hardware");
         ImGui::Text("witch is another form of mouse and keyboard emulation");
         ImGui::Text("This is the device i would recomend to you");
         ImGui::InputText("ip",kmboxIpBuffer,bufferSize);
         ImGui::InputText("port",kmboxPortBuffer,bufferSize);
         ImGui::InputText("mac",kmboxMacBuffer,bufferSize);
         if(ImGui::Button("Connect!")){
            std::println("[+] Connecting to kmbox!");
            if(Kmbox::connect(kmboxIpBuffer,kmboxPortBuffer,kmboxPortBuffer)){
               std::println("[+] Connected to kmbox!");
            } else {
               std::println("[-] Failed to connect to kmbox!");
            }
         }
         ImGui::SameLine();
         if(ImGui::Button("Test Kmbox!")){
            std::println("[+] Testing to kmbox!");
            if(Kmbox::test()){
               std::println("[+] Kmbox test passed!");
            } else {
               std::println("[-] Kmbox test failed!");
            }
         }
         ImGui::EndTabItem();
      }
      if (ImGui::BeginTabItem("Macku ")){
         ImGui::Text("This is another form of mouse emulation with hardware");
         ImGui::Text("So obvoiusly you need to purchace a macku");
         ImGui::EndTabItem();
      }
      if (ImGui::BeginTabItem("Native ")){
         ImGui::Text("This is just your native oparating system way of moving the mouse");
         ImGui::Text("witch would be a system call most likely and detected");
         ImGui::Text("so i would recemend otherwise");
         ImGui::EndTabItem();
      }
      ImGui::EndTabBar();
   }
   ImGui::End();
}

void realGUI(){
   ImGui::NewFrame();
   deviceGUI();
   ImGui::Render();
}

void buildGUI(){
   ImGui_ImplGlfw_NewFrame();
   ImGui_ImplOpenGL3_NewFrame();
   ImGui::PushFont(myFont);
   realGUI();
   ImGui::PopFont();
   ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void terminate(){
   ImGui_ImplOpenGL3_Shutdown();
   ImGui_ImplGlfw_Shutdown();
   ImGui::DestroyContext();

   glfwDestroyWindow(window);
   glfwTerminate();
}

void loop(){
   glfwPollEvents();
   glfwGetFramebufferSize(window, &width, &height);
   glViewport(0, 0, width, width);
   glClearColor(0.1,0.1,0.1,1);
   glClear(GL_COLOR_BUFFER_BIT);
   buildGUI();
   glfwSwapBuffers(window);
}

void init(){
   initBuffers();
   std::println("[+] Starting initalization process!");
   if(!glfwInit())
      std::println("[-] GLFW failed to initalize!");
   window = glfwCreateWindow(width,height,"Hello",NULL,NULL);
   glfwMakeContextCurrent(window);
   if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
      std::println("[-] GLAD failed to initalize!");
   
   ImGui::CreateContext();
   io = ImGui::GetIO();

   ImGui_ImplGlfw_InitForOpenGL(window,true);
   ImGui_ImplOpenGL3_Init();

   myFont = io.Fonts->AddFontFromFileTTF("/home/dom/.local/share/fonts/JetBrainsMonoNerdFontMono-Regular.ttf", 18.0f);
}