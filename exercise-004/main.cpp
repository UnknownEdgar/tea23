#include <fmt/chrono.h>
#include <fmt/format.h>
#include <filesystem>
#include <string>

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

#include "CLI/CLI.hpp"
#include "config.h"
#include "image.h"

auto main(int argc, char **argv) -> int
{
    CLI::App app{PROJECT_NAME};

    // CLI Parameter für Ausgabeordner und Basename
    std::string output_dir = "./output";
    std::string base_filename = "processed_image";

    app.add_option("-o,--output-dir", output_dir, "Verzeichnis zum Speichern der Bilder");
    app.add_option("-f,--file-base", base_filename, "Basisname für Ausgabedateien");

    try
    {
        app.set_version_flag("-V,--version", fmt::format("{} {}", PROJECT_VER, PROJECT_BUILD_DATE));
        app.parse(argc, argv);
    }
    catch (const CLI::ParseError &e)
    {
        return app.exit(e);
    }

    fmt::print("Hello, {}!\n", app.get_name());

    int length = sizeof(image) / sizeof(image[0]);

    fmt::println("Width: {}", image_width);
    fmt::println("Height: {}", image_height);
    fmt::println("Length Array: {}", length);

    // Bild als cv::Mat aus rohen RGB-Pixeln erzeugen
    cv::Mat img(image_height, image_width, CV_8UC3, (void*)image);
    fmt::println("Originalbild geladen.");

    // Filter 1: Graustufen
    cv::Mat gray_img;
    cv::cvtColor(img, gray_img, cv::COLOR_BGR2GRAY);
    fmt::println("Graustufen-Bild erstellt.");

    // Filter 2: Gaussian Blur
    cv::Mat blurred_img;
    cv::GaussianBlur(img, blurred_img, cv::Size(15, 15), 0);
    fmt::println("Gaussian Blur (15x15) angewandt.");

    // Filter 3: Canny Kantenfilter
    cv::Mat edges;
    cv::Canny(gray_img, edges, 50, 150);
    fmt::println("Canny Kantenfilter (Thresholds 50/150) angewandt.");

    // Ausgabe der Filterparameter
    fmt::println("Filterparameter:");
    fmt::println(" - Gaussian Blur Kernelgröße: 15x15");
    fmt::println(" - Canny Schwellenwerte: 50 (low), 150 (high)");

    // Verzeichnis anlegen (wenn nicht existiert)
    std::filesystem::create_directories(output_dir);

    // Dateipfade zusammensetzen
    std::string gray_path = output_dir + "/" + base_filename + "_gray.png";
    std::string blur_path = output_dir + "/" + base_filename + "_blurred.png";
    std::string edges_path = output_dir + "/" + base_filename + "_edges.png";

    // Bilder speichern
    cv::imwrite(gray_path, gray_img);
    cv::imwrite(blur_path, blurred_img);
    cv::imwrite(edges_path, edges);

    fmt::println("Gespeicherte Bilder:");
    fmt::println(" - Graustufen: {}", gray_path);
    fmt::println(" - Gaussian Blur: {}", blur_path);
    fmt::println(" - Canny Kanten: {}", edges_path);

    return 0;
}
