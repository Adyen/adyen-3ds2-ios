// swift-tools-version:5.3
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "Adyen3DS2",
    platforms: [
        .iOS(.v10),
        .macOS(.v10_15)
    ],
    products: [
        .library(
            name: "Adyen3DS2",
            targets: ["Adyen3DS2"])
    ],
    dependencies: [],
    targets: [
        .binaryTarget(
            name: "Adyen3DS2",
            path: "XCFramework/Dynamic/Adyen3DS2.xcframework")
    ]
)
