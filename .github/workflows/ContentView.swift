//
//  ContentView.swift
//  ThreeDS2Test
//
//  Created by Mohamed Eldoheiri on 26/05/2023.
//

import SwiftUI
import Adyen3DS2

struct ContentView: View {
    @State
    private var transaction: ADYTransaction?
    
    var body: some View {
        VStack {
            Image(systemName: "globe")
                .imageScale(.large)
                .foregroundColor(.accentColor)
            Text("Hello, world!")
        }
        .padding()
        .task {
            ADYService.service(with: .init(),
                               appearanceConfiguration: nil) { service in
                do {
                    let transaction = try service.transaction(withMessageVersion: "2.2.0")
                    self.transaction = transaction
                    
                    // Print warnings.
                    Swift.print("---- Warnings (\(service.warnings.count)) ----")
                    service.warnings.forEach { Swift.print($0) }
                } catch {
                    print(error)
                }
            }
        }
    }
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
    }
}
