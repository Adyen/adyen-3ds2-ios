version = '2.4.3'

Pod::Spec.new do |spec|
  spec.name                   = 'Adyen3DS2'
  spec.version                = version
  spec.license                = { :type => 'Apache License, Version 2.0', :file => 'LICENSE' }
  spec.homepage               = 'https://adyen.com'
  spec.authors                = { 'Adyen' => 'support@adyen.com' }
  spec.summary                = 'Accept 3D Secure 2.0 payments via Adyen.'
  spec.source                 = { :git => 'https://github.com/adyen/adyen-3ds2-ios.git', :tag => version }
  spec.vendored_frameworks    = 'XCFramework/Dynamic/Adyen3DS2.xcframework'
  spec.ios.deployment_target  = '10.0'
end
