version = `agvtool vers -terse`

Pod::Spec.new do |spec|
  spec.name                   = 'Adyen3DS2'
  spec.version                = version
  spec.license                = { :type => 'Apache License, Version 2.0', :file => 'LICENSE' }
  spec.homepage               = 'https://adyen.com'
  spec.authors                = { 'Joost van Dijk' => 'joost.vandijk@adyen.com' }
  spec.summary                = 'Accept 3D Secure 2.0 payments via Adyen.'
  spec.ios.deployment_target  = '10.0'
  spec.source                 = { :git => 'git@code.is.adyen.com:iOS/adyen-3ds2-ios.git', :tag => version }
  spec.source_files           = 'Adyen3DS2/**/*.{h,m}'
  spec.prefix_header_file     = 'Adyen3DS2/Other/Adyen3DS2-Prefix.pch'
  spec.resource_bundles       = {
    'Adyen3DS2' => [
      'Adyen3DS2Resources/**/*.{png,der,sha256}'
    ]
  }
  spec.dependency             'tommath'
end
