version = '2.2.2'

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
  
  # workaround for binary dependencies, see https://github.com/CocoaPods/CocoaPods/issues/10065
  #   spec.pod_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  #   spec.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
end
