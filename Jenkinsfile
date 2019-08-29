pipeline {
	agent { label 'ccs9' }
	
	stages {
	
		stage('Import Projects') {
			steps {
				sh 'ccstudio -noSplash -data . -application com.ti.ccstudio.apps.projectImport -ccs.location els-f280049c || true'
			}
		}
		
		stage('Build Debug') {
			steps {
				sh 'ccstudio -noSplash -data . -application com.ti.ccstudio.apps.projectBuild -ccs.workspace --ccs.buildType full -ccs.configuration Debug'
			}
		}
		
		stage('Build Release') {
			steps {
				sh 'ccstudio -noSplash -data . -application com.ti.ccstudio.apps.projectBuild -ccs.workspace --ccs.buildType full -ccs.configuration Release'
			}
		}
		
	}
}